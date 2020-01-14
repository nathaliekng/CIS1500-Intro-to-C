# include <stdio.h>
int main() {
	int date;
	double cabbageLb;
	double tomatoesLb;
	double mushroomsLb;
	double redPeppersLb;
	double carrotsLb;
	double parsleyLb;
	double galaApplesLb;
	double bananaLb;
	double subtotal;
	int subtotal2;
	double discount2;
	double discount3;
	//initializes the variables to hold the ones digit, tens digit and the sum of the previous two variables 
	int onesDigit;
	int tensDigit;
	int sumDigit;

	printf("Welcome to Fresh Produce Inc.");
	printf("\n");
	printf("------------------------------------------------------");
	printf("\n");
	printf("Please enter todays date (a number between 1 and 31): ");
	scanf("%d", &date);

	//Find sum of digits using integer division and modulus
	tensDigit = date/10;
	onesDigit = date%10;
	sumDigit = tensDigit + onesDigit;

	printf("\n");
	printf("Please indicate the quantity you wish to purchase for each item.");
	printf("\n\n");

	printf("	Cabbage:	Price: 60 cents per lb		How many pounds? ");
	scanf("%lf", &cabbageLb);
	printf("\n");
	printf("	Tomatoes:	Price: 80 cents per lb		How many pounds? ");
	scanf("%lf", &tomatoesLb);
	printf("\n");
	printf("	Mushrooms:	Price: $1.20 per lb		How many pounds? ");
	scanf("%lf", &mushroomsLb);
	printf("\n");
	printf("	Red Peppers:	Price: $2.40 per lb		How many pounds? ");
	scanf("%lf", &redPeppersLb);
	printf("\n");
	printf("	Carrots:	Price: $1.10 per lb		How many pounds? ");
	scanf("%lf", &carrotsLb);
	printf("\n");
	printf("	Parsley:	Price: 69 cents per bunch	How many bunches? ");
	scanf("%lf", &parsleyLb);
	printf("\n");
	printf("	Gala Apples:	Price: $1.29 per lb		How many pounds? ");
	scanf("%lf", &galaApplesLb);
	printf("\n");
	printf("	Banana:		Price: 57 cents per lb		How many pounds? ");
	scanf("%lf", &bananaLb);
	printf("\n");

	printf("Your order is:\n\n");

	//Calculating the price using users input of pounds and multiplying by set price
	printf("	Cabbage 	%.2lflb@ $0.60	$ %.2lf\n", cabbageLb, cabbageLb * 0.60);
	printf("	Tomatoes	%.2lflb@ $0.80	$ %.2lf\n", tomatoesLb, tomatoesLb * 0.80);
	printf("	Mushrooms	%.2lflb@ $1.20	$ %.2lf\n", mushroomsLb, mushroomsLb * 1.20);
	printf("	Red Peppers	%.2lflb@ $2.40	$ %.2lf\n", redPeppersLb, redPeppersLb * 2.40);
	printf("	Carrots		%.2lflb@ $1.10	$ %.2lf\n", carrotsLb, carrotsLb * 1.10);
	printf("	Parsley		%.0lf@ $0.69 each	$ %.2lf\n", parsleyLb, parsleyLb * 0.69);
	printf("	Gala Apples	%.2lflb@ $1.29	$ %.2lf\n", galaApplesLb, galaApplesLb * 1.29);
	printf("	Banana		%.2lflb@ $0.57	$ %.2lf\n", bananaLb, bananaLb * 0.57);
	printf("\n\n");

	//Calculating subtotal by adding the total prices previously calculated 
	subtotal = (cabbageLb*0.60)+(tomatoesLb*0.80)+(mushroomsLb*1.20)+(redPeppersLb*2.40)+(carrotsLb*1.10)+(parsleyLb*0.69)+(galaApplesLb*1.29)+(bananaLb*0.57);
	subtotal2 = subtotal; //Takes the subtotal calculated above, and turns it into an integer with no decimal points
	//Calculating discounts off of subtotal after discount one
	discount2 = subtotal2*0.05;
	discount3 = subtotal2*0.01;

	printf("	Sub-total				: $%.2lf", subtotal);
	printf("\n");
	printf("	Sub-total after discount 1		: $%d", subtotal2);
	printf("\n");
	
	//Applies discount two, if the subtotal divided by the sum of digits equal to 0
	if(subtotal2 % sumDigit == 0) {
		printf("	Sub-total after discounts 2 and 3	: $%.2lf\n", subtotal2 - (discount2+discount3)); //Subtracting discount two and three from subtotal2
	}
	else {
		printf("	Sub-total after discount 3		: $%.2lf\n", subtotal2 - discount3); //Finding subtotal after discount three by subtracting discount three from subtotal2
	}

	printf("	Taxes (13%%)				: $%.2lf\n", subtotal*0.13); //Caclulating tax by multiplcation of first subtotal and tax of 13 percent
	printf("\n");
	printf("	Your total comes to ");

	if(subtotal2 % sumDigit == 0) {
		printf("$%.2lf\n",(subtotal*0.13)+((subtotal2-(discount2+discount3)))); //Adds the subtotal with all discounts and tax
	}
	else {
		printf("$%.2lf\n",(subtotal*0.13)+(subtotal2-discount3)); //Adds subtotal with discount one and three
	}

	printf("\n");
	printf("	Thank you for shopping with Fresh Produce Inc. Have a great day.\n");

return 0;
}

