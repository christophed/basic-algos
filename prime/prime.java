class Prime {
  public static void printPrimeUpTo(int num) {
    for (int i = 1; i <= num; ++i) {
      if (isPrime(i)) {
        System.out.println(i);
      }
    }
  }

  public static boolean isPrime(int num) {
    if (num == 2 || num == 3 || num == 5) {
      return true;
    } else if (num <= 1) {
      return false;
    }

    for (int i = 2; i <= 5; ++i) {
      if (num % i == 0) {
 //       System.out.println("" + num + " divides by " + i);
        return false;
      }
    }

    int sieve[] = { 2, 4 };

    int divisor = 5;
    int sieve_counter = 0;

    while (divisor < (int)Math.sqrt(num)) {
      divisor += sieve[sieve_counter];
      if (num % divisor == 0) {
//        System.out.println("" + num + " divides by " + divisor);
        return false;
      }

      sieve_counter = (sieve_counter + 1) % sieve.length;
    }

    return true;
  }

  public static void usage() {
    System.out.println("Usage: java [program] [number]");
  }

  public static void main(String args[]) {
    if (args.length == 0) {
      usage();
      return;
    }

    int primeCandidate = 0;

    try {
      primeCandidate = Integer.parseInt(args[0]);
    } catch(NumberFormatException e) {
      usage();
      return;
    }
/*
    if (isPrime(primeCandidate)) {
      System.out.println("A prime number!");
    }
    else {
      System.out.println("Not a prime number.");
    }
    */
    printPrimeUpTo(primeCandidate);
  }
}
