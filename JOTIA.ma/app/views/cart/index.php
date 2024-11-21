<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <title>سلة التسوق</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1>سلة التسوق</h1>
    <table>
        <thead>
            <tr>
                <th>اسم المنتج</th>
                <th>الكمية</th>
                <th>السعر</th>
                <th>الإجمالي</th>
                <th>حذف</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($cartItems as $item): ?>
                <tr>
                    <td><?php echo $item['name']; ?></td>
                    <td><?php echo $item['quantity']; ?></td>
                    <td><?php echo $item['price']; ?> درهم</td>
                    <td><?php echo $item['price'] * $item['quantity']; ?> درهم</td>
                    <td><a href="/cart/remove?product_id=<?php echo $item['product_id']; ?>">حذف</a></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>
</html>
