<?php
class Review {
    private $db;

    public function __construct($db) {
        $this->db = $db;
    }

    // إضافة مراجعة
    public function addReview($productId, $userId, $rating, $comment) {
        $stmt = $this->db->prepare("INSERT INTO reviews (product_id, user_id, rating, comment) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("iiis", $productId, $userId, $rating, $comment);
        return $stmt->execute();
    }

    // استرجاع مراجعات المنتج
    public function getProductReviews($productId) {
        $stmt = $this->db->prepare("SELECT * FROM reviews WHERE product_id = ?");
        $stmt->bind_param("i", $productId);
        $stmt->execute();
        $result = $stmt->get_result();
        return $result->fetch_all(MYSQLI_ASSOC);
    }
}
?>
