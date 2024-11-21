<?php
require_once 'config/database.php';
require_once 'app/models/SupportTicket.php';
require_once 'middlewares/AuthMiddleware.php';

class SupportController {
    private $supportTicketModel;

    public function __construct($db) {
        AuthMiddleware::isAuthenticated();
        $this->supportTicketModel = new SupportTicket($db);
    }

    // عرض جميع التذاكر الخاصة بالمستخدم
    public function index() {
        session_start();
        $userId = $_SESSION['user_id'];
        $tickets = $this->supportTicketModel->getUserTickets($userId);
        include 'app/views/support/index.php';
    }

    // إنشاء تذكرة دعم جديدة
    public function create() {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $userId = $_SESSION['user_id'];
            $subject = $_POST['subject'];
            $message = $_POST['message'];

            $this->supportTicketModel->createTicket($userId, $subject, $message);
            header('Location: /support');
        } else {
            include 'app/views/support/create.php';
        }
    }

    // عرض تفاصيل التذكرة
    public function view() {
        $ticketId = $_GET['id'];
        $ticket = $this->supportTicketModel->getTicketById($ticketId);
        include 'app/views/support/view.php';
    }
}
?>
