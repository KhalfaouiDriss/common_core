<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <title>الطلبات</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1>الطلبات</h1>
    <table>
        <thead>
            <tr>
                <th>رقم الطلب</th>
                <th>المنتج</th>
                <th>الكمية</th>
                <th>حالة الطلب</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($orders as $order): ?>
                <tr>
                    <td><?php echo $order['id']; ?></td>
                    <td><?php echo $order['product_id']; ?></td>
                    <td><?php echo $order['quantity']; ?></td>
                    <td>قيد المعالجة</td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>
</html>
