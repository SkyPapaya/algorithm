package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Map {
    //邻接矩阵可以表示的最大顶点数
    int maxSize = 10;
    //顶点信息
    char[] V = new char[maxSize];
    //邻接矩阵
    int[][] arcs = new int[maxSize][maxSize];
    //边数
    int e;
    //顶点数
    int n;

    //在图中查找顶点v，找到后返回其在顶点数组中的索引号，若不存在，返回-1
    public int LocateVex(char v) {
        int i;
        for (i = 0; i < n; i++) {
            if (V[i] == v) {
                return i;
            }
        }
        return -1;
    }

    //判断是不是连通图
    public static boolean isConnected(int[][] adjacencyMatrix) {
        int n = adjacencyMatrix.length;
        boolean[] visited = new boolean[n];
        // Start DFS from the first vertex
        dfs(adjacencyMatrix, 0, visited);

        // Check if all vertices are visited
        for (boolean v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }

    //深度优先遍历
    public static void dfs(int[][] adjacencyMatrix, int vertex, boolean[] visited) {
        visited[vertex] = true;
        for (int i = 0; i < adjacencyMatrix.length; i++) {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                dfs(adjacencyMatrix, i, visited);
            }
        }
    }

    public static boolean isEulerian(int[][] adjacencyMatrix) {
        int n = adjacencyMatrix.length;

        // Check if the graph is connected
        if (!isConnected(adjacencyMatrix)) {
            return false;
        }

        // Check if all vertices have even degree
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                degree += adjacencyMatrix[i][j];
            }
            if (degree % 2 != 0) {
                return false;
            }
        }

        return true;
    }

    public static List<Integer> findEulerianCircuit(int[][] adjacencyMatrix) {
        List<Integer> circuit = new ArrayList<>();
        int n = adjacencyMatrix.length;

        if (!isEulerian(adjacencyMatrix)) {
            System.out.println("这个图不是欧拉图");
            return circuit;
        }

        // 创建一个邻接矩阵的备份
        int[][] tempMatrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tempMatrix[i][j] = adjacencyMatrix[i][j];
            }
        }

        // 从0开始寻找欧拉路
        eulerianCircuitDFS(tempMatrix, 0, circuit);

        return circuit;
    }

    public static void eulerianCircuitDFS(int[][] adjacencyMatrix, int vertex, List<Integer> circuit) {
        for (int i = 0; i < adjacencyMatrix.length; i++) {
            if (adjacencyMatrix[vertex][i] == 1) {
                // 从图中删除这个度
                adjacencyMatrix[vertex][i] = 0;
                adjacencyMatrix[i][vertex] = 0;

                // 从下一个节点开始寻找
                eulerianCircuitDFS(adjacencyMatrix, i, circuit);
            }
        }

        // 向欧拉图中添加这个节点
        circuit.add(vertex);
    }


    public boolean CreateAdj() { //创建无向图的邻接矩阵
        char v1, v2;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入图的顶点数及边数");
        System.out.print("顶点数n=");
        n = sc.nextInt();
        System.out.print("边数e=");
        e = sc.nextInt();
        if (e > 2 * n) {
            System.out.println("边与节点的数量关系不正确");
            return false;
        }
        //随机构造
        System.out.print("请输入图的顶点信息：");
        String str = sc.next();
        //输入顶点信息
        for (int i = 0; i < n; i++) {
            V[i] = str.charAt(i);
        }//初始化邻接矩阵
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arcs[i][j] = 0;
            }
        }
        for (int k = 0; k < e; k++) {
            //从A-节点数之间随机生成点
            Random random = new Random();
            v1 = (char) (random.nextInt(n) + 65);
            v2 = (char) (random.nextInt(n) + 65);
            //确定两个顶点在图G中的位置
            int i = LocateVex(v1);
            int j = LocateVex(v2); //算法6-1
            if (i >= 0 && j >= 0) {
                arcs[i][j] = 1;
                arcs[j][i] = 1;
            }
        }
        System.out.println("图的邻接矩阵表示：");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(" " + arcs[i][j]);
            }
            System.out.println();
        }
        //判断是不是连通图
        if (isConnected(arcs)) {
            System.out.println("这个图是一个连通图");
        } else {
            System.out.println("这个图不是一个连通图");
        }
        if (isEulerian(arcs)) {
            System.out.println("这个图是一个欧拉图");
            List<Integer> eulerianCircuit = findEulerianCircuit(arcs);
            System.out.println("欧拉回路是: " + eulerianCircuit);
        } else {
            System.out.println("这个图不是一个欧拉图");
        }
        return true;
    }
}