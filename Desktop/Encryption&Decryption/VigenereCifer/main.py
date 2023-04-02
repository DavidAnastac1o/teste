def encrypt(message, key):
    """
    Encrypts a message using a Vigenère cipher with a given key.
    """
    encrypted_message = ""

    for i, char in enumerate(message):
        if char.isalpha():
            # Get the shift amount for this character based on the key
            shift = ord(key[i % len(key)]) - 65
            # Shift the character by the given amount
            encrypted_char = chr((ord(char) - 65 + shift) % 26 + 65)
            encrypted_message += encrypted_char
        else:
            # Leave non-alphabetic characters as is
            encrypted_message += char

    return encrypted_message

def decrypt(encrypted_message, key):
    """
    Decrypts an encrypted message using a Vigenère cipher with a given key.
    """
    message = ""

    for i, char in enumerate(encrypted_message):
        if char.isalpha():
            # Get the shift amount for this character based on the key
            shift = ord(key[i % len(key)]) - 65
            # Shift the character back by the given amount
            decrypted_char = chr((ord(char) - 65 - shift) % 26 + 65)
            message += decrypted_char
        else:
            # Leave non-alphabetic characters as is
            message += char

    return message

# Example usage
message = "HELLO, WORLD!"
key = "MYKEY"
encrypted_message = encrypt(message, key)
print(encrypted_message)

decrypted_message = decrypt(encrypted_message, key)
print(decrypted_message)
