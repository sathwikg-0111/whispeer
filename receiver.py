
# receiver.py

import socket
import os
from audio_utils import play_audio

HOST = ''         # Listen on all interfaces
PORT = 5001       # Same port as sender

# Folder to store incoming voice files
if not os.path.exists("messages"):
    os.mkdir("messages")

s = socket.socket()
s.bind((HOST, PORT))
s.listen(1)
print("[📡] Waiting for a voice message...")

conn, addr = s.accept()
print(f"[📥] Message received from {addr}")

file_path = "messages/incoming.wav"
with open(file_path, "wb") as f:
    while True:
        data = conn.recv(1024)
        if not data:
            break
        f.write(data)

conn.close()

# Play received audio
play_audio(file_path)
