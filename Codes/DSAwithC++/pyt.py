import hashlib

def string_to_md5(input_string):
    # Create an MD5 hash object
    md5_hash = hashlib.md5()

    # Update the hash object with the bytes of the input string
    md5_hash.update(input_string.encode('utf-8'))

    # Get the hexadecimal digest of the hash
    md5_digest = md5_hash.hexdigest()

    return md5_digest

if __name__ == "__main__":
    input_string = "password"
    md5_result = string_to_md5(input_string)
    print(f"MD5 hash of '{input_string}': {md5_result}")
