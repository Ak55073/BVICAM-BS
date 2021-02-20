class Waffle{
	String flavour;
	int price;
	
	Waffle(String flavour, int price){
		this.flavour = flavour;
		this.price = price;
	}
	
	boolean equals (Waffle other){
		if (this.flavour == other.flavour && this.price == other.price){
			return true;
		} else{
			return false;
		}
	}
	
	@Override
    public String toString() {
		return this.flavour;
	}
	
}

class WaffleMain{
	public static void main(String args[]){
		Waffle ob1 = new Waffle("Vannila",300);
		Waffle ob2 = new Waffle("Chocolate",500);
		System.out.println("BP.Waffle 1: "+ob1);
		System.out.println("BP.Waffle 1: "+ob2);
		System.out.println("Are 2 waffle equal: "+ob1.equals(ob2));
		System.out.println("Are 2 waffle same: "+(ob1==ob2));
	}
}