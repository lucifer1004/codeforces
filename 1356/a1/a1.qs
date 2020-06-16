namespace Solution {

    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            unitary(q);
            return MResetZ(q) == One ? 1 | 0;            
        }
    }
}

