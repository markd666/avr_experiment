# avr_experiment
Test out building AVR with C++ STLport library with bazel

## Try to build with following command
`bazelisk build //main:hello-world   --platforms @AvrToolchain//platforms:pcb_v_2_1 
                                    --incompatible_enable_cc_toolchain_resolution=true 
                                    --features=c++14`
