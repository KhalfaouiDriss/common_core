<?php
require_once 'config/database.php';
require_once 'app/models/Product.php';

class ProductController {
    private $productModel;

    public function __construct($db) {
        $this->productModel = new Product($db);
    }

    // عرض المنتجات
    public function index() {
        $products = $this->productModel->getAllProducts();
        include 'app/views/products/index.php';
    }

    // إضافة منتج جديد
    public function add() {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $name = $_POST['name'];
            $price = $_POST['price'];
            $description = $_POST['description'];
            $image = $_FILES['image']['name'];

            // رفع الصورة إلى مجلد الصور
            move_uploaded_file($_FILES['image']['tmp_name'], "public/images/" . $image);

            $this->productModel->addProduct($name, $price, $description, $image);
            header('Location: /products');
        } else {
            include 'app/views/products/add.php';
        }
    }
}
?>
