<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>إنشاء حساب</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1>إنشاء حساب جديد</h1>
    <form action="/register" method="POST">
        <label for="username">اسم المستخدم:</label>
        <input type="text" name="username" required><br>

        <label for="email">البريد الإلكتروني:</label>
        <input type="email" name="email" required><br>

        <label for="password">كلمة المرور:</label>
        <input type="password" name="password" required><br>

        <button type="submit">تسجيل</button>
    </form>
</body>
</html>
