import socket

def connect_and_send(ip, port, message):
    # Create a socket object using IPv4 and TCP protocol
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Connect to the server
        sock.connect((ip, port))
        print(f"Connected to {ip} on port {port}")

        # Send data
        # Ensure the message is a byte string
        if isinstance(message, str):
            message = message.encode('utf-8')
        sock.sendall(message)
        print("Message sent successfully")

    except socket.error as e:
        print(f"Socket error: {e}")

    finally:
        # Close the socket to clean up
        sock.close()
        print("Connection closed")

# Example usage
ip_address = '54.89.247.175'  # Replace with the server's IP address
port_number = 8080            # Replace with the server's port number
char_buffer = input("What iformation are you going to ask to the server: ")  # The message you want to send

connect_and_send(ip_address, port_number, char_buffer)