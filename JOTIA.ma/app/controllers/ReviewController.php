<?php
require_once 'config/database.php';
require_once 'app/models/Review.php';

class ReviewController {
    private $reviewModel;

    public function __construct($db) {
        $this->reviewModel = new Review($db);
    }

    // إضافة مراجعة
    public function add() {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $productId = $_POST['product_id'];
            $userId = $_SESSION['user_id'];
            $rating = $_POST['rating'];
            $comment = $_POST['comment'];

            $this->reviewModel->addReview($productId, $userId, $rating, $comment);
            header('Location: /products/view?id=' . $productId);
        }
    }
}
?>
