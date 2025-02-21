import requests

# بيانات التطبيق (استبدلها بالبيانات الخاصة بك)
CLIENT_ID = "YOUR_CLIENT_ID"
CLIENT_SECRET = "YOUR_CLIENT_SECRET"
TOKEN_URL = "https://api.intra.42.fr/oauth/token"

# الحصول على Access Token
def get_access_token():
    data = {
        "grant_type": "client_credentials",
        "client_id": CLIENT_ID,
        "client_secret": CLIENT_SECRET
    }
    
    response = requests.post(TOKEN_URL, data=data)
    
    if response.status_code == 200:
        return response.json()["access_token"]
    else:
        raise Exception(f"Failed to get token: {response.text}")

# استدعاء API باستخدام Access Token
def get_my_data():
    access_token = get_access_token()
    headers = {
        "Authorization": f"Bearer {access_token}"
    }
    
    response = requests.get("https://api.intra.42.fr/v2/me", headers=headers)
    
    if response.status_code == 200:
        return response.json()
    else:
        raise Exception(f"Failed to fetch data: {response.text}")

# تنفيذ الكود وعرض بيانات المستخدم
if __name__ == "__main__":
    user_data = get_my_data()
    print(user_data)
