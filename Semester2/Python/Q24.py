import pyodbc

class DatabaseManager:
    def __init__(self):
        server = 'remotemysql.com'
        database = 'XKd55uAdUX'
        username = 'XKd55uAdUX'
        password = 'ukDacpGXnX'
        connection_string = (
            'DRIVER={MySQL ODBC 8.0 ANSI Driver};'
            f'SERVER={server};'
            f'DATABASE={database};'
            f'UID={username};'
            f'PWD={password};'
        )
        cnxn = pyodbc.connect(connection_string)
        self.cursor = cnxn.cursor()

    def create_table(self):
        self.cursor.execute(f"CREATE TABLE users "
                            f"(Name VARCHAR(50), Email VARCHAR(50))")

    def delete_table(self):
        self.cursor.execute(f"DROP TABLE users;")

    def insert_into_table(self, name, email):
        self.cursor.execute(f"INSERT INTO users (Name, Email)"
                            f" VALUES ('{name}', '{email}')")

    def update_table(self, name, email):
        self.cursor.execute(f"UPDATE users SET "
                            f"Email='{email}' where Name='{name}';")

    def print_all(self):
        self.cursor.execute('SELECT * FROM users;')
        for row in self.cursor:
            print(row)


if __name__ == "__main__":
    database = DatabaseManager()
    database.create_table()

    database.insert_into_table("Abhinav", "ak55073")
    database.insert_into_table("S1-Abhinav", "abhinav.kumar20")
    print("Record Inserted!")
    database.print_all()

    database.update_table("Abhinav", "ak55073@gmail.com")
    database.update_table("S1-Abhinav", "abhinav.kumar20@gmail.com")
    print("Record Updated!")
    database.print_all()

    database.delete_table()
