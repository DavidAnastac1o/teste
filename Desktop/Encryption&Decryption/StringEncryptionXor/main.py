def encrypt_message(message, key):
    """
    Criptografa uma mensagem de 32 bits utilizando a operação XOR com uma chave de 32 bits.
    """
    message_bytes = message.encode('utf-8')
    message_bits = int.from_bytes(message_bytes, byteorder='big')
    encrypted_message = message_bits ^ key
    return encrypted_message

def decrypt_message(encrypted_message, key):
    """
    Descriptografa uma mensagem de 32 bits criptografada utilizando a operação XOR com uma chave de 32 bits.
    """
    decrypted_message_bits = encrypted_message ^ key
    decrypted_message_bytes = decrypted_message_bits.to_bytes((decrypted_message_bits.bit_length() + 7) // 8, byteorder='big')
    decrypted_message = decrypted_message_bytes.decode('utf-8')
    return decrypted_message

# Exemplo de uso
message = "hello world"
key = 0xA5C43210  # 32 bits
encrypted_message = encrypt_message(message, key)
print("Mensagem criptografada: ", bin(encrypted_message))

decrypted_message = decrypt_message(encrypted_message, key)
print("Mensagem descriptografada: ", decrypted_message)
