
# sender.py

import socket
from audio_utils import record_audio

# Step 1: Ask for IP of the receiving device
receiver_ip = input("Enter the receiver's IP address: ")
port = 5001  # Same as receiver

# Step 2: Record audio and save as file
filename = "out.wav"
record_audio(filename, duration=5)

# Step 3: Send audio file to receiver
s = socket.socket()
try:
    s.connect((receiver_ip, port))
    print("[🔗] Connected to receiver!")

    with open(filename, "rb") as f:
        data = f.read()
        s.sendall(data)

    print("[✅] Voice message sent.")
except Exception as e:
    print(f"[❌] Failed to send message: {e}")
finally:
    s.close()
