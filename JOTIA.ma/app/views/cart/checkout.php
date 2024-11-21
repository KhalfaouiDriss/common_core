<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <title>الدفع</title>
    <link rel="stylesheet" href="/public/css/style.css">
</head>
<body>
    <h1>الدفع</h1>
    <form action="/cart/checkout" method="POST">
        <label for="card_number">رقم البطاقة:</label>
        <input type="text" name="card_number" required><br>

        <label for="expiry_date">تاريخ الانتهاء:</label>
        <input type="text" name="expiry_date" required><br>

        <label for="cvv">CVV:</label>
        <input type="text" name="cvv" required><br>

        <button type="submit">إتمام الدفع</button>
    </form>
</body>
</html>
