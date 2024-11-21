<?php
class Cart {
    private $db;

    public function __construct($db) {
        $this->db = $db;
    }

    // استرجاع المنتجات في السلة
    public function getCartItems() {
        $sql = "SELECT * FROM cart";
        $result = $this->db->query($sql);
        return $result->fetch_all(MYSQLI_ASSOC);
    }

    // إضافة منتج إلى السلة
    public function addToCart($productId, $quantity) {
        $stmt = $this->db->prepare("INSERT INTO cart (product_id, quantity) VALUES (?, ?)");
        $stmt->bind_param("ii", $productId, $quantity);
        return $stmt->execute();
    }

    // إزالة منتج من السلة
    public function removeFromCart($productId) {
        $stmt = $this->db->prepare("DELETE FROM cart WHERE product_id = ?");
        $stmt->bind_param("i", $productId);
        return $stmt->execute();
    }
}
?>
