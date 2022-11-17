from tkinter import messagebox as msg
import pandas
from  pandastable import Table
import pyodbc
import tkinter as tk

class MainWindow(tk.Frame):
    def __init__(self,parent):
        parent.update()
        super().__init__(parent,width=1080,height=500,bg = 'grey')
        self.pack_propagate(0)

class ResultTable(tk.Frame):
    def __init__(self,parent):
        super().__init__(parent,bg = 'grey')
        

    def update_list(self,df):
        self.pt = Table(self, dataframe=df,
                                showtoolbar=False,width=700, showstatusbar=False)
        self.pt.show()
        return

class SQLButtons(tk.Frame):
    def __init__(self,parent,table):
        super().__init__(parent,bg = 'grey')
        self.table = table
        my_font = ("Arial", 12)
        get_emp_sales_btn = tk.Button(self,text="Get Employees in Sales",font=my_font,command=self.get_emp)
        get_emp_sales_btn.pack(pady=(0,5),anchor='nw')

        # get_vin_black_btn = tk.Button(self,text="Get Vin# of All Black Cars",font=my_font,command=self.get_black)
        # get_vin_black_btn.pack(pady=(5,5))

        # get_emp_sales_btn = tk.Button(self,text="Get Emp name Who Worked > 30 hrs",font=my_font,command=self.get_emp_30hrs)
        # get_emp_sales_btn.pack(pady=(5,5))

        get_car_sold_black_btn = tk.Button(self,text="Get Black Cars Sold",font=my_font,command=self.get_black_sold)
        get_car_sold_black_btn.pack(pady=(5,5),anchor='nw')

        get_emp_sal_70_btn = tk.Button(self,text="Get Employees who salary > $70,000",font=my_font,command=self.get_emp_sal_70)
        get_emp_sal_70_btn.pack(pady=(5,5),anchor='nw')

        get_color_leather_btn = tk.Button(self,text="Get Colors of Cars with Leather",font=my_font,command=self.get_color_leather)
        get_color_leather_btn.pack(pady=(5,5),anchor='nw')

        get_model_fabric_btn = tk.Button(self,text="Get Model of cars with Leather",font=my_font,command=self.get_model_fab)
        get_model_fabric_btn.pack(pady=(5,5),anchor='nw')

        get_manager_btn = tk.Button(self,text="Get Managers",font=my_font,command=self.get_managers)
        get_manager_btn.pack(pady=(5,5),anchor='nw')

        get_dept_sal_high_btn = tk.Button(self,text="Insert John Doe",font=my_font,command=self.insert_john)
        get_dept_sal_high_btn.pack(pady=(5,5),anchor='nw')

        update_jobs_btn = tk.Button(self,text="Update Salary by 10%",font=my_font,command=self.update_sal)
        update_jobs_btn.pack(pady=(5,5),anchor='nw')

        delete_emp_btn = tk.Button(self,text="Delete Emp over 40",font=my_font,command=self.delete_40)
        delete_emp_btn.pack(pady=(5,5),anchor='nw')

        insert_hrs_btn = tk.Button(self,text="Insert Hrs",font=my_font,command=self.insert_hrs)
        insert_hrs_btn.pack(pady=(5,5),anchor='nw')

    def insert_hrs(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        cur.execute('INSERT INTO Hours_Worked (empSsn, hours, date, deptNum) VALUES ("345-34-0912", 45, "4/18/2022", 12)')
        cur.commit()
        df = pandas.read_sql_query('SELECT * FROM Hours_Worked',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def delete_40(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        cur.execute('DELETE FROM Employee WHERE age > 40')
        cur.commit()
        df = pandas.read_sql_query('SELECT * FROM Employee',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def update_sal(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        cur.execute('UPDATE Jobs SET salary = salary * 1.1')
        cur.commit()
        df = pandas.read_sql_query('SELECT firstName, lastName, name, salary FROM Employee a, Jobs b WHERE a.jobTitle = b.name',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def get_managers(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT firstName, lastName FROM Employee a, Department b WHERE a.ssn = b.manager ',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def insert_john(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        try:
            cur.execute('INSERT INTO Employee (ssn, firstName, lastName, age, address, jobTitle, deptNum) VALUES ("123-45-6789", "John", "Doe", 45, "1234 Michigan Ave, Canton, MI 48145", "Sales", 2)')
            cur.commit()
            df = pandas.read_sql_query('SELECT * FROM Employee',conn)
            self.table.update_list(df)
            cur.close()
            conn.close()
        except: 
            df = pandas.read_sql_query('SELECT * FROM Employee',conn)
            self.table.update_list(df)
            cur.close()
            conn.close()
            msg.showerror("Error","Employee with that SSN already exist!")


    def get_model_fab(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT model FROM Vehicles WHERE intMaerial = "Leather"',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def get_color_leather(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT extColor FROM Vehicles WHERE intMaerial = "Leather"',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def get_emp_sal_70(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT firstName, lastName FROM Employee a, Jobs b WHERE a.jobTitle = b.name AND b.salary > 70000',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def get_emp(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT firstName, lastName FROM Employee a, Department b WHERE a.deptNum = b.deptNum AND b.name = "Sales"',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()
     
    def get_black(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT vinNum FROM Vehicles WHERE extColor = "Black"',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()
     
    def get_emp_30hrs(self):
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT DISTINCT firstName, lastName FROM Employee a, Hours_Worked b WHERE a.ssn = b.empSsn AND b.hours > 30',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

    def get_black_sold(self):
        
        conn = pyodbc.connect("DRIVER={SQLite3 ODBC Driver};server=localhost\sqlexpress;DATABASE=CarDealership.db;Trusted_connection=yes")
        cur = conn.cursor()
        df = pandas.read_sql_query('SELECT orderNum,price FROM Cars_Sold a, Vehicles b WHERE a.vinNum = b.vinNum AND b.extColor = "Black"',conn)
        self.table.update_list(df)
        cur.close()
        conn.close()

class App:
    def __init__(self,root):
        root.pack_propagate(0)
        main_window = MainWindow(root)
        main_window.pack()
        result_table = ResultTable(main_window)
        buttons = SQLButtons(main_window,result_table)
        
        
        buttons.pack(side="left",anchor='n',padx=(10,10))
        result_table.pack()


if __name__ == "__main__":
    root = tk.Tk()
    
    root.geometry("1080x500")
    my_app = App(root)
    root.mainloop()