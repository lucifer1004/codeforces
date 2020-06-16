namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        let qs = register!;
        if (Length(qs) > 1) {
            (Controlled Solve)([qs[0]], LittleEndian(qs[1 ...]));
        }
        X(qs[0]);
    }
}