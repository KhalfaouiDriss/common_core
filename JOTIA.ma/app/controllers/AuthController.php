<?php
require_once 'config/database.php';
require_once 'app/models/User.php';

class AuthController {
    private $userModel;

    public function __construct($db) {
        $this->userModel = new User($db);
    }

    public function login() {
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $email = $_POST['email'];
            $password = $_POST['password'];

            $user = $this->userModel->login($email, $password);
            if ($user) {
                session_start();
                $_SESSION['user_id'] = $user['id'];
                header('Location: /dashboard');
            } else {
                $error = "خطأ في البريد الإلكتروني أو كلمة المرور";
                include 'app/views/auth/login.php';
            }
        } else {
            include 'app/views/auth/login.php';
        }
    }

    public function logout() {
        session_start();
        session_destroy();
        header('Location: /login');
    }
}
?>
