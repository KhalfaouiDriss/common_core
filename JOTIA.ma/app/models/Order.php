<?php
class Order {
    private $db;

    public function __construct($db) {
        $this->db = $db;
    }

    // استرجاع جميع الطلبات
    public function getAllOrders() {
        $sql = "SELECT * FROM orders";
        $result = $this->db->query($sql);
        return $result->fetch_all(MYSQLI_ASSOC);
    }

    // إنشاء طلب جديد
    public function createOrder($userId, $cartItems) {
        $stmt = $this->db->prepare("INSERT INTO orders (user_id, product_id, quantity) VALUES (?, ?, ?)");
        foreach ($cartItems as $item) {
            $stmt->bind_param("iii", $userId, $item['product_id'], $item['quantity']);
            $stmt->execute();
        }
    }
}
?>
