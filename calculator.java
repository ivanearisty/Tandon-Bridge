import java.util.Scanner;
import java.util.Stack;

public class calculator {

	// tbh you go back in history one by one,
	// so we can go back in history by popping off of a stack of operations
	Stack<Operation> operations;

	calculator() {
		operations = new Stack<Operation>();
	}

	/*
	 * The operation class will encapsualte the logic of all the actions the user
	 * performs on the calculator, before pressing enter or equals.
	 * When the operation is complete, user presses enter and this object is
	 * processed for an answer and added to the prev operations stack.
	 */
	class Operation {
		final private int solution;
		final private String prefixRepresentation;
		final private String postfixRepresentation;

		Operation() {
			System.err.println("Cannot have an empty operation");
			throw new ExceptionInInitializerError();
		}

		Operation(String input) {
			prefixRepresentation = input;
			postfixRepresentation = toPostfix();
			solution = solve();
		}

		private String toPostfix() {

			Stack<Character> operators = new Stack<>();
			StringBuilder output = new StringBuilder();

			for (int i = 0; i < this.prefixRepresentation.length(); i++) {
				
				char ch = this.prefixRepresentation.charAt(i);

				if (Character.isDigit(ch)) {
					output.append(ch);

					//if we at the end or the next character is not a digit we add a separator
					if (i + 1 >= this.prefixRepresentation.length() || !Character.isDigit(this.prefixRepresentation.charAt(i + 1))) {
						output.append(" ");
					}

				} else if (ch == '(') {
					operators.push(ch);
				} else if (ch == ')') {
					while (!operators.isEmpty() && operators.peek() != '(') {
						output.append(operators.pop()).append(" ");
					}
					operators.pop();
				} else if (isOperator(ch)) {
					while (!operators.isEmpty() && precedence(ch) <= precedence(operators.peek())) {
						output.append(operators.pop()).append(" ");
					}
					operators.push(ch);
				}
			}

			while (!operators.isEmpty()) {
				output.append(operators.pop()).append(" ");
			}
			return output.toString();
		}

		private int solve() {

			Stack<Integer> stack = new Stack<>();
			Scanner scanner = new Scanner(this.postfixRepresentation);

			while (scanner.hasNext()) {
				if (scanner.hasNextInt()) {
					stack.push(scanner.nextInt());
				} else {
					
					int rhs = stack.pop();
					int lhs = stack.pop();
					
					char operator = scanner.next().charAt(0);
					
					switch (operator) {
						case '+':
							stack.push(lhs + rhs);
							break;
						case '-':
							stack.push(lhs - rhs);
							break;
						case '*':
							stack.push(lhs * rhs);
							break;
						case '/':
							stack.push(lhs / rhs);
							break;
					}
				}
			}

			scanner.close();
			return stack.pop();
		}

		private int precedence(char ch) {
			switch (ch) {
				case '+':
				case '-':
					return 1;
				case '*':
				case '/':
					return 2;
				default:
					return -1;
			}
		}

		public void display() {
			System.out.print("The solution for the equation: " + prefixRepresentation + ". Is: ");
			System.out.println(solution);
		}

	}

	/**
	 * This method processes input from the user and creates a new operation and
	 * adds it to the stack
	 * 
	 * @return 0 if we were successful in creating a new operation, 1 otherwise
	 */
	private int processOperation(String input) {
		int check = operations.size();
		operations.push(new Operation(input));
		if (check != operations.size())
			return 0;
		else
			return 1;
	}

	/**
	 * Displays the current operation at the top of the stack
	 */
	private void display() {
		operations.peek().display();
	}

	public static void main(String[] args) {
		calculator calc = new calculator();
		run(calc);
	}

	private static void run(calculator calc) {
		Scanner in = new Scanner(System.in);
		String input;

		System.out.println("Hey, I am an integer calculator. I support the following operations: +, -, /, and *.");
		System.out.println("Write out the operation you want like: 2+3/(4+2)");
		System.out.println("Follow it by an enter to process.");
		System.out.println("You can also type \"back\" to go back in time and see previous operations!");
		System.out.println("Type \"end\" to exit.");

		while (true) {

			input = in.nextLine();
			input = input.replaceAll("\\s+", "");

			if (input.equals("end")) {
				in.close();
				System.exit(0);
			}

			if (input.equals("back")) {
				calc.goBack();
				continue;
			}

			if (input.isEmpty() || !isValid(input)) {
				System.out.println("Mhmm... something feels off about this one");
				continue;
			}

			calc.processOperation(input);
			calc.display();
		}

	}

	private static boolean isValid(String input) {
		for (char ch : input.toCharArray()) {
			if (!Character.isDigit(ch) && !isOperator(ch))
				return false;
		}
		return true;
	}

	private static boolean isOperator(char ch) {
		if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '(' || ch == ')')
			return true;
		else
			return false;
	}

	private void goBack() {
		if (operations.size() == 0)
			System.out.println("Nothing to go back to!");
		else
			operations.pop().display();
	}
}