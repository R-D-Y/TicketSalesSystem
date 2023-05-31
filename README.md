# TicketSalesSystem
A simple ticket sales system implemented in C, featuring multiple cashier processes and a display showing the remaining available seats


## Description

The Ticket Sales System simulates a scenario where multiple cashiers sell tickets concurrently. Each cashier is represented by a separate process, and they compete to sell the available seats. The system also includes a display that shows the current number of remaining seats in real-time.

## Features

- Concurrent ticket sales with multiple cashier processes
- Real-time display of remaining seats
- Randomized ticket selling behavior for each cashier
- Efficient use of system resources through concurrent processing

## Usage

1. Compile the program using a C compiler.
2. Run the compiled executable with the following command-line arguments:
```plaintext
  ./ticket_sales <number_of_cashiers> <title> <total_seats>
  ```


  

- `<number_of_cashiers>`: The number of cashier processes to create.
- `<title>`: The title of the ticket sales system.
- `<total_seats>`: The total number of available seats for sale.

3. Observe the ticket sales process as the cashiers compete and the remaining seats are displayed.

## Example

To run the Ticket Sales System with 3 cashiers and 100 total seats, use the following command:
  
  ```plaintext
  ./ticket_sales 3 "Ticket Sales Demo" 100
```
    
    
## Contributing

Contributions to this project are welcome. If you find any issues or would like to suggest improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

    
