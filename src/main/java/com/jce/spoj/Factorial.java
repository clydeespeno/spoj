package com.jce.spoj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Factorial {

    public static void main(String... args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int tests = Integer.parseInt(readLine(reader));

        while(tests-- > 0) {
            System.out.println(computeZeros(Integer.parseInt(readLine(reader))));
        }
    }

    public static int computeZeros(int facNum) {
        int fivePow = (int)(Math.log10(facNum)/Math.log10(5));
        int zeros = 0;
        for(int p = 1; p <= fivePow; zeros += facNum/(int)(Math.pow(5, p++)));
        return zeros;
    }

    private static String readLine(BufferedReader reader) throws IOException {
        return reader.readLine();
    }
}
