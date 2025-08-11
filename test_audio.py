import sounddevice as sd
from scipy.io.wavfile import write, read

# Record Audio
duration = 3  # seconds
fs = 44100
print("[🎙️] Recording...")
recording = sd.rec(int(duration * fs), samplerate=fs, channels=2)
sd.wait()
write("test.wav", fs, recording)
print("[✅] Recording saved as test.wav")

# Play Audio
print("[🔊] Playing back...")
rate, data = read("test.wav")
sd.play(data, rate)
sd.wait()
print("[✅] Done.")
