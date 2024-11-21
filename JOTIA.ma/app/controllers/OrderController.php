<?php
require_once 'config/database.php';
require_once 'app/models/Order.php';

class OrderController {
    private $orderModel;

    public function __construct($db) {
        $this->orderModel = new Order($db);
    }

    // عرض الطلبات
    public function index() {
        $orders = $this->orderModel->getAllOrders();
        include 'app/views/orders/index.php';
    }

    // تأكيد الطلب
    public function confirm() {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $cartItems = $_POST['cart'];
            $userId = $_SESSION['user_id'];

            $this->orderModel->createOrder($userId, $cartItems);
            header('Location: /orders');
        }
    }
}
?>
