<?php
class Product {
    private $db;

    public function __construct($db) {
        $this->db = $db;
    }

    // استرجاع جميع المنتجات
    public function getAllProducts() {
        $sql = "SELECT * FROM products";
        $result = $this->db->query($sql);
        return $result->fetch_all(MYSQLI_ASSOC);
    }

    // إضافة منتج جديد
    public function addProduct($name, $price, $description, $image) {
        $stmt = $this->db->prepare("INSERT INTO products (name, price, description, image) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("sdsb", $name, $price, $description, $image);
        return $stmt->execute();
    }
}
?>
