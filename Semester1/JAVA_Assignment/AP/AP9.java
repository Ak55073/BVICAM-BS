import java.lang.Math;
class AP9{
	public static void main(String[] args){
		if (args.length < 2){
			System.out.println("Input missing. Values for principal, rate, time (required) and interest period(optional).");
			return;
		} else if (args.length == 3){
			FinancialCalculator calc = new FinancialCalculator(Double.parseDouble(args[0]),Double.parseDouble(args[1]),Double.parseDouble(args[2]));
			double si =  calc.simpleInterest();
			System.out.println("Simple Interest: "+si+" Amount: "+(Double.parseDouble(args[0])+si));
			System.out.print("Final value: "+calc.finalVal());
		} else {
			FinancialCalculator calc = new FinancialCalculator(
			Double.parseDouble(args[0]),
			Double.parseDouble(args[1]),
			Double.parseDouble(args[2]),
			Double.parseDouble(args[3]));
			double ci =  calc.compoundInterest();
			System.out.println("Compound Interest: "+ci);
			System.out.print("Final value: "+calc.finalVal());
		}
	}
}

class FinancialCalculator{
	double principal, rate, time, n;
	FinancialCalculator(double principal,double rate,double time){
		this.principal = principal;
		this.rate = rate;
		this.time = time;
	}
	FinancialCalculator(double principal,double rate,double time,double n){
		this.principal = principal;
		this.rate = rate;
		this.time = time;
		this.n = n;
	}
	double simpleInterest(){
		return ((principal*(rate / 100)*time));
	}
	double compoundInterest(){
		double ci = principal * (Math.pow((1+((rate / 100)/n)), (n*time)));
		return ci;
	}
	double finalVal(){
		double val = principal * (Math.pow((1+(rate / 100)), time));
		return val;
	}
} 
