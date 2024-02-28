import mysql.connector
from dotenv import load_dotenv
load_dotenv()
import os

def connect():
    return mysql.connector.connect(
        host=os.getenv("DB_HOST"),
        user=os.getenv("DB_USER"),
        passwd=os.getenv("DB_PASS"),
        database=os.getenv("DB_NAME")
    )

def get_all():
    conn = connect()
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM CUSTOMERS")
    result = cursor.fetchall()
    conn.close()
    return result

print(get_all()) 