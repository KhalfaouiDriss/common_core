<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>تسجيل الدخول</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1>تسجيل الدخول</h1>
    <form action="/login" method="POST">
        <label for="email">البريد الإلكتروني:</label>
        <input type="email" name="email" required><br>

        <label for="password">كلمة المرور:</label>
        <input type="password" name="password" required><br>

        <button type="submit">دخول</button>
    </form>
</body>
</html>
