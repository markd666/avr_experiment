# avr_experiment
Test out building AVR with C++ STLport library with bazel

## Try to build with following command - This should work
`bazelisk build //main:hello-world   --platforms @AvrToolchain//platforms:pcb_v_2_1 
                                    --incompatible_enable_cc_toolchain_resolution=true 
                                    --features=c++14`


## Then try this
`bazelisk build //libs:libs  --platforms @AvrToolchain//platforms:pcb_v_2_1 
                            --incompatible_enable_cc_toolchain_resolution=true 
                            --features=c++14` 
