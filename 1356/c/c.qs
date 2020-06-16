namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (qs : Qubit[]) : Unit {
        using (anc = Qubit()) { 
            repeat {
                for (q in qs) {
                    H(q);
                }
                Controlled X(qs, anc);
                let res = MResetZ(anc);
            } 
            until (res == Zero)
            fixup {
                ResetAll(qs);
            }
        }
        Controlled X(qs[0 .. 0], qs[1]);
        X(qs[0]);
    }
}
