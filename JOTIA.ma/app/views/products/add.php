<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <title>إضافة منتج</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1>إضافة منتج جديد</h1>
    <form action="/products/add" method="POST" enctype="multipart/form-data">
        <label for="name">اسم المنتج:</label>
        <input type="text" name="name" required><br>

        <label for="price">السعر:</label>
        <input type="number" name="price" required><br>

        <label for="description">الوصف:</label>
        <textarea name="description" required></textarea><br>

        <label for="image">صورة المنتج:</label>
        <input type="file" name="image" required><br>

        <button type="submit">إضافة المنتج</button>
    </form>
</body>
</html>
