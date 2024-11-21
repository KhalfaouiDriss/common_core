<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <title>قائمة المنتجات</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1>المنتجات المتاحة</h1>
    <div class="product-list">
        <?php foreach ($products as $product): ?>
            <div class="product-item">
                <img src="/public/images/<?php echo $product['image']; ?>" alt="<?php echo $product['name']; ?>">
                <h2><?php echo $product['name']; ?></h2>
                <p><?php echo $product['description']; ?></p>
                <p>السعر: <?php echo $product['price']; ?> درهم</p>
            </div>
        <?php endforeach; ?>
    </div>
</body>
</html>
