# SCADE: Embedded Longitudinal Flight System Implementation
## Objectives

- The aim of the project is switcing from a high-level specification (textual) to a detailed specifiaction (SCADE formalism).
- Traceability between the high-level specification (textual) to a detailed specification (SCADE formalism) using the gateway "Requirements Management".
- Validation using simulation tools and formal proof.
- Verification of the validation using the model test coverage tool (MTC).

## Solution

### Nodes

#### *Autopilot*

Added transition between "Climb" and "Descent" in order to cope with sensor errors that may output passing from one state to the other but without passing through the "Cruising" state. 

#### *CalculDensity*

If the value for the altitude is very high, the output for the density would be negative as a result of the formula 0.745 - altitude [m] * 5.2 *0.00001 = density [kg/m^3]. In this case, an "If.. Then.. Else" choice node has been added in order to give the density a value of 0 if the previous formula returs a negative value for the density.

#### *CalculSpeed*

Proceeding in the same way that in the "CalculDensity" node, if "density" is greater than 0 and the result of "2*(pStop - pStatic)/density" is greater than 0, then the value for the speed is calculated using the previous expression. Otherwise the output for the speed is zero.

#### *CalculVerticalSpeed*

The calculation of the vertical speed has been assigned to this particular node because it will be useful to use it later for "DescentProof".

#### *CalculSlope*

If "speedPlane" is 0, then the slope value is also 0. This condition takes into account the possibility of dividing by "speedPlane" when its value is zero. Also, a limiter between -1 and 1 has been added before the ASIN node.

--------------------------------------------------------------------------------------------------------------------------

### Model Test Coverage

The model is covered at 100% with the scenario described below.

--------------------------------------------------------------------------------------------------------------------------

### Scenario

The scenario provided for the MTC "Test_Req_15.sss" doesn't cover the "CalculDensity" node entirely. A new scenario called "MTC-scenario.sss" and located in folder "Tests" folder has been created by modifying the previous scenario in order to fully cover all the nodes.

--------------------------------------------------------------------------------------------------------------------------

### Formal proof - Nodes Observer/Proof

Theses nodes have been implemented in order to carry formal proofs. In the case of "StallProof", we want to verify that it is not possible to have an stall alarm if the incidence is less or equal to 12°. The property was implemented by verifying that when "incidence" is equal or samller than "stallingIncidenceThreshold" (12°), then "alarmIndicatorLightsStall" is always false. The same idea has been implemented for the crashing alarm (CrashProof) and the vertical speed alarm (DescentProof).
