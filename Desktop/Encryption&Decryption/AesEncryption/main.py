from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# Generate a 256-bit encryption key
key = get_random_bytes(32)

# Define the message to be encrypted
message = b'This is a secret message'

# Create an AES cipher object with the key
cipher = AES.new(key, AES.MODE_EAX)

# Encrypt the message
ciphertext, tag = cipher.encrypt_and_digest(message)

# Print the encrypted message and tag
print('Encrypted message:', ciphertext)
print('Tag:', tag)

# Decrypt the message
cipher = AES.new(key, AES.MODE_EAX, cipher.nonce)
decrypted_message = cipher.decrypt_and_verify(ciphertext, tag)

# Print the decrypted message
print('Decrypted message:', decrypted_message)
