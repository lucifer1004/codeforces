namespace Solution {
    open Microsoft.Quantum.MachineLearning;
 
    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return ([ControlledRotation((0, new Int[0]), PauliY, 0)], ([3.155519321249991], 0.004599999999999993));
    }
}