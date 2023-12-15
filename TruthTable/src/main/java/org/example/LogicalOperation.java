package org.example;

public class LogicalOperation {

    int disjunction(int x, int y) {//析取+
        if (x == 1 || y == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    int conjunction(int x, int y) {//合取*
        if (x == y && x == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    int nagation(int x) {//-否定
        if (x == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int implication(int x, int y) {//蕴涵
        if (x == 1 && y == 0) {
            return 0;
        } else {
            return 1;
        }
    }

    int equivalence(int x, int y) {//等价
        if (x == y) {
            return 1;
        } else {
            return 0;
        }
    }

}
