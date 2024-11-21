<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <title>عرض المنتج</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1><?php echo $product['name']; ?></h1>
    <p><?php echo $product['description']; ?></p>
    <p>السعر: <?php echo $product['price']; ?> درهم</p>

    <h2>التقييمات:</h2>
    <ul>
        <?php foreach ($reviews as $review): ?>
            <li>
                <strong><?php echo $review['rating']; ?>/5</strong>
                <p><?php echo $review['comment']; ?></p>
            </li>
        <?php endforeach; ?>
    </ul>

    <h3>إضافة مراجعة:</h3>
    <form action="/reviews/add" method="POST">
        <input type="hidden" name="product_id" value="<?php echo $product['id']; ?>">
        <label for="rating">التقييم (من 1 إلى 5):</label>
        <input type="number" name="rating" min="1" max="5" required><br>
        <label for="comment">التعليق:</label>
        <textarea name="comment" required></textarea><br>
        <button type="submit">إرسال المراجعة</button>
    </form>
</body>
</html>
