<?php
// إعداد الاتصال بقاعدة البيانات
$servername = "localhost";
$username = "root";  // ضع هنا اسم المستخدم لقاعدة البيانات
$password = "";      // ضع هنا كلمة المرور لقاعدة البيانات
$dbname = "ecommerce";  // اسم قاعدة البيانات

// إنشاء الاتصال
$conn = new mysqli($servername, $username, $password, $dbname);

// التحقق من الاتصال
if ($conn->connect_error) {
    die("فشل الاتصال بقاعدة البيانات: " . $conn->connect_error);
}
?>
