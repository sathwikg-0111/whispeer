
# audio_utils.py

import sounddevice as sd
from scipy.io.wavfile import write, read

def record_audio(filename, duration=5, fs=44100):
    print(f"[🎙️] Recording for {duration} seconds...")
    audio = sd.rec(int(duration * fs), samplerate=fs, channels=2)
    sd.wait()
    write(filename, fs, audio)
    print(f"[💾] Saved: {filename}")

def play_audio(filename):
    fs, data = read(filename)
    print(f"[🔊] Playing: {filename}")
    sd.play(data, fs)
    sd.wait()
