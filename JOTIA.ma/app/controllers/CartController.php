<?php
require_once 'config/database.php';
require_once 'app/models/Cart.php';

class CartController {
    private $cartModel;

    public function __construct($db) {
        $this->cartModel = new Cart($db);
    }

    // عرض سلة التسوق
    public function index() {
        $cartItems = $this->cartModel->getCartItems();
        include 'app/views/cart/index.php';
    }

    // إضافة منتج إلى السلة
    public function add() {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $productId = $_POST['product_id'];
            $quantity = $_POST['quantity'];

            $this->cartModel->addToCart($productId, $quantity);
            header('Location: /cart');
        }
    }

    // إزالة منتج من السلة
    public function remove() {
        $productId = $_GET['product_id'];
        $this->cartModel->removeFromCart($productId);
        header('Location: /cart');
    }
}



?>


