from tkinter import *
import webbrowser

# Dictionary of users and passwords
users = {
    "user1": "password1",
    "user2": "password2",
    "user3": "password3"
}

# Dictionary of URLs for each page
pages = {
    "user1": "https://www.google.com",
    "user2": "https://www.youtube.com",
    "user3": "https://www.facebook.com"
}

# Function to check login credentials
def login():
    # Get username and password from user input
    username = username_entry.get()
    password = password_entry.get()

    # Check if username and password are valid
    if username in users and password == users[username]:
        print("Login successful!")
        # Destroy login window
        login_window.destroy()
        # Open user's page
        page = pages[username]
        page_window = Tk()
        # Open URL in web browser
        webbrowser.open_new(page)
    else:
        print("Invalid username or password.")

# Create login window
login_window = Tk()
login_window.title("Login")

# Create username and password labels and entries
username_label = Label(login_window, text="Username:")
username_label.pack()
username_entry = Entry(login_window)
username_entry.pack()
password_label = Label(login_window, text="Password:")
password_label.pack()
password_entry = Entry(login_window, show="*")
password_entry.pack()

# Create login button
login_button = Button(login_window, text="Login", command=login)
login_button.pack()

# Run login window
login_window.mainloop()


"""
from tkinter import *

# Dictionary of users and passwords
users = {
    "user1": "password1",
    "user2": "password2",
    "user3": "password3"
}

# Dictionary of pages for each user and their respective color
pages = {
    "user1": {"page": "page1", "color": "red"},
    "user2": {"page": "page2", "color": "green"},
    "user3": {"page": "page3", "color": "blue"}
}

# Function to check login credentials
def login():
    # Get username and password from user input
    username = username_entry.get()
    password = password_entry.get()

    # Check if username and password are valid
    if username in users and password == users[username]:
        print("Login successful!")
        # Destroy login window
        login_window.destroy()
        # Open user's page
        page = pages[username]["page"]
        color = pages[username]["color"]
        page_window = Tk()
        page_window.title(page)
        page_window.geometry("300x300")
        # Create square with different color for each page
        square = Canvas(page_window, width=200, height=200, bg=color)
        square.place(relx=0.5, rely=0.5, anchor="center")
    else:
        print("Invalid username or password.")

# Create login window
login_window = Tk()
login_window.title("Login")

# Create username and password labels and entries
username_label = Label(login_window, text="Username:")
username_label.pack()
username_entry = Entry(login_window)
username_entry.pack()
password_label = Label(login_window, text="Password:")
password_label.pack()
password_entry = Entry(login_window, show="*")
password_entry.pack()

# Create login button
login_button = Button(login_window, text="Login", command=login)
login_button.pack()

# Run login window
login_window.mainloop()
"""