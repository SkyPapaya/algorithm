package org.example;

import java.util.Scanner;

public class matrix {
    public static void simplify(){
        Scanner input = new Scanner(System.in);
        int A, B;
        System.out.println("请输入矩阵的行数");

        do {
            A = input.nextInt();
            if (A <= 0) {
                System.out.println("输入的矩阵的行数错误！");
                System.out.println("请重新输入：");
            }
        } while (A <= 0);
        System.out.println("请输入矩阵的列数：");
        do {
            B = input.nextInt();
            if (B <= 0) {
                System.out.println("输入的矩阵的列数错误！");
                System.out.println("请重新输入：");
            }
        } while (B <= 0);
        int[][] C = new int[A][B];
        for (int i = 0; i < A; i++) {
            System.out.printf("请输入第%d行的所有数", i + 1);
            for (int j = 0; j < B; j++) {
                C[i][j] = input.nextInt();
            }
        }
        int D = A, E, F, G, G1, G2;
        do {
            F = A - D;
            for (int i = F + 1; i < A; i++) {
                if (C[F][F] != 0) {
                    break;
                } else {
                    if (C[i][F] != 0) {
                        for (int j = 0; j < B; j++) {
                            E = C[F][j];
                            C[F][j] = C[i][j];
                            C[i][j] = E;
                        }
                        break;
                    }
                }
            }
            for (int i = 0; i < A; i++) {
                if (i != F && C[i][F] != 0) {
                    if (C[F][F] != 0) {
                        if (C[i][F] < 0) {
                            for (G = C[F][F]; G % (-C[i][F]) != 0; ) {
                                G += C[F][F];
                            }
                            G1 = G / C[F][F];
                            G2 = G / (-C[i][F]);
                            for (int j = 0; j < B; j++) {
                                C[i][j] = C[i][j] * G2 + C[F][j] * G1;
                            }
                        } else {
                            for (G = C[F][F]; G % C[i][F] != 0; ) {
                                G += C[F][F];
                            }
                            G1 = G / C[F][F];
                            G2 = G / C[i][F];
                            for (int j = 0; j < B; j++) {
                                C[i][j] = C[i][j] * G2 - C[F][j] * G1;
                            }
                        }
                    }
                }
            }
            D--;
        } while (D > 0);
        int[] H = new int[A];
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if (C[i][j] != 0) {
                    H[i] = B - j;
                    break;
                }
            }
        }
        for (int i = 0; i < A; i++) {
            for (int j = i + 1; j < A; j++) {
                if (H[i] < H[j]) {
                    for (int k = 0; k < B; k++) {
                        E = C[i][k];
                        C[i][k] = C[j][k];
                        C[j][k] = E;
                    }
                    E = H[i];
                    H[i] = H[j];
                    H[j] = E;
                }
            }
        }
        int[] R = new int[A];
        for (int i = 0; i < A; i++) {
            for (int j = 0; j <= i; j++) {
                if (C[i][j] != 0) {
                    R[i] = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < A; i++) {
            if (R[i] == 0) {
                for (int j = 0; j < B; j++) {
                    if (C[i][j] != 0) {
                        if (C[i][j] < 0) {
                            for (int Q = 0; Q < i; Q++) {
                                if (C[Q][j] != 0) {
                                    for (G = C[Q][j]; G % (-C[i][j]) != 0; ) {
                                        G += C[Q][j];
                                    }
                                    G1 = G / C[Q][j];
                                    G2 = G / (-C[i][j]);
                                    for (int k = 0; k < B; k++) {
                                        C[Q][k] = C[Q][k] * G1 + C[i][k] * G2;
                                    }
                                }
                            }
                        } else {
                            for (int Q = 0; Q < i; Q++) {
                                if (C[Q][j] != 0) {
                                    for (G = C[Q][j]; G % C[i][j] != 0; ) {
                                        G += C[Q][j];
                                    }
                                    G1 = G / C[Q][j];
                                    G2 = G / C[i][j];
                                    for (int k = 0; k < B; k++) {
                                        C[Q][k] = C[Q][k] * G1 - C[i][k] * G2;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        int U, J1;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if (C[i][j] != 0) {
                    if (C[i][j] < 0) {
                        for (int k = 0; k < B; k++) {
                            C[i][k] = -C[i][k];
                        }
                    }
                    break;
                }
            }
        }
        System.out.println("化简结果为");
        for (int i = 0; i < A; i++) {
            E = 0;
            U = 0;
            for (int j = 0; j < B; j++) {
                if (C[i][j] != 0) {
                    E = C[i][j];
                    U = 1;
                    break;
                }
            }
            if (U == 1) {
                for (int j = 0; j < B; j++) {
                    if (j == 0) {
                        if (C[i][j] % E != 0) {
                            if (C[i][j] % E < 0) {
                                J1 = AAA(Math.abs(C[i][j]), Math.abs(E));
                                System.out.print("-" + Math.abs(C[i][j]) / J1 + "/" + Math.abs(E) / J1);
                            } else {
                                J1 = AAA(Math.abs(C[i][j]), Math.abs(E));
                                System.out.print(Math.abs(C[i][j]) / J1 + "/" + Math.abs(E) / J1);
                            }
                        } else {
                            System.out.print(C[i][j] / E);
                        }
                    } else {
                        if (C[i][j] % E != 0) {
                            if (C[i][j] % E < 0) {
                                J1 = AAA(Math.abs(C[i][j]), Math.abs(E));
                                System.out.print(" " + "-" + Math.abs(C[i][j]) / J1 + "/" + Math.abs(E) / J1);
                            } else {
                                J1 = AAA(Math.abs(C[i][j]), Math.abs(E));
                                System.out.print(" " + Math.abs(C[i][j]) / J1 + "/" + Math.abs(E) / J1);
                            }
                        } else {
                            System.out.print(" " + C[i][j] / E);
                        }
                    }
                }
                System.out.println();
            } else {
                for (int j = 0; j < B; j++) {
                    if (j == 0) {
                        System.out.print("0");
                    } else {
                        System.out.print(" 0");
                    }
                }
                System.out.println();
            }
        }
    }

    public static int AAA(int J1, int J2) {
        while (J1 != J2) {
            if (J1 > J2) {
                J1 = J1 - J2;
            } else {
                J2 = J2 - J1;
            }
        }
        return J1;
    }
    }

