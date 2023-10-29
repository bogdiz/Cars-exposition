# Cars-exposition
In May, the sports car fair is organized, allowing enthusiasts to indulge in models from the COUPE class, HOT-HATCH (small and compact hatchback models with powerful engines based on regular models), CABRIO (convertible models with metal or fabric roofs), and SUPERSPORT (high-speed cars like Audi R8, Bugatti Veyron, Lexus LF-A, etc.). Some of the supersport cars can be sold directly at the exhibition if the transaction is made with on-the-spot payment.
Data structure: vector or list <pair<car, price>> (stores the sold cars and their selling price; if a car is unsold, the price is -1)

Add all relevant fields for modeling this problem.
Build the template class Exhibition, which contains the total number of exhibited cars (automatically incremented) and a dynamically allocated vector of car objects.
Construct a specialization for the SUPERSPORT type, which includes the total number of exhibited supersport cars (automatically decremented when a car is sold), the number of cars sold (automatically incremented), and two dynamically allocated vectors of pointers to supersport car objects, used to manage cars in stock and those sold. Overload the -= operator to update the data in the class when a car is sold.
