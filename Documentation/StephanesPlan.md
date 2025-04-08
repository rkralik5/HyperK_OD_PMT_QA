# qa-doc

General information about the HK OD PMT QA current design and plan.

### Goal

Batch test all OD PMTs being delivered directly in Japan before assembly with the WLS plate and mount. 
A set of specifications previously defined needs to be satisfied within a specific range.
The features to be characterized are:
- Gain: the ratio between the number of photo-electrons generated and the charge collected downstream the tube. Typically, this is done at very low-light (i.e, at the single photo-electron level), and the goal is to measure the charge by integrating the pulse recorded by the PMT. That charge (in the order of pC) must be within the input votage range of the PMTs (typically, 900 to 1300V).
- SPE: single photo-electron resolution. The histogram of the charge collected when the PMTs operate at the single-photon regime must be characterized by a response fitting function. Typically, the histogram looks like a gaussian peak at mean 0 (the pedestal), and a peak at mean XX (the single photo-electron peak). The gaussian peak of the single photo-electron must be a certain width compared to the pedestal.
- Relative QE: relative quantum efficiency. The amount of photons collected with respect to a standard source of light must above a certain threshold at a similar gain between PMTs.
- Dark rates: the number of 'dark' signals, which are the pulses recorded by the PMTs when no light around.

### Procedure

### 1. Setup

#### Equipment Required:

- Photomultiplier Tube (PMT)
- Light source (preferably a pulsed LED or a laser)
- Optical attenuator or neutral density filters
- High voltage power supply
- Pulse generator (if using a pulsed light source)
- Data acquisition system (oscilloscope or a specialized PMT readout electronics)
- Dark chamber or enclosure to shield from ambient light
- Amplifier and discriminator (if needed)

### 2. Experimental Procedure

#### A. Dark Count Measurement:

1. **Place the PMT in a dark enclosure** to avoid any ambient light.
2. **Connect the PMT to the high voltage power supply** and set the operating voltage according to the PMT specifications.
3. **Record the dark counts** over a specified period. This helps in understanding the baseline noise level of the PMT.

#### B. Single Photo-Electron Spectrum Measurement:

1. **Use a pulsed light source**: An LED or laser that can produce very low light levels. The light pulses should be brief (nanoseconds range) to ensure they produce single photo-electrons.
2. **Attenuate the light**: Use optical filters to reduce the light intensity such that the average number of photo-electrons per pulse is much less than one (typically around 0.1 photo-electrons per pulse). This ensures that most pulses produce either zero or one photo-electron.
3. **Align the light source** with the PMT's photocathode.
4. **Trigger the PMT** with the pulse generator (synchronized with the light pulses if using a pulsed source).

### 3. Data Acquisition and Analysis

1. **Acquire the PMT signals**: Use an oscilloscope or a data acquisition system to record the PMT pulses. Ensure the system has sufficient bandwidth to capture the fast PMT signals.
2. **Histogram the pulse heights**: Collect a large number of pulse height measurements and create a histogram. This histogram represents the distribution of pulse heights (or charge) from the PMT.

### 4. Analysis of the SPE Spectrum

1. **Identify the peaks**: In the histogram, identify the peaks corresponding to the dark counts (zero photo-electrons) and the single photo-electron events.
2. **Fit the histogram**: The histogram can be fitted with a model that includes a Gaussian (or Poisson) distribution for the single photo-electron peak and another Gaussian for the dark counts.
3. **Determine the gain**: The separation between the dark count peak and the single photo-electron peak is proportional to the PMT gain. The gain can be calculated by determining the mean value of the single photo-electron peak and dividing it by the electron charge.

### 5. Calculation of PMT Parameters

#### Gain:
$$
G = \frac{\mu_\text{SPE}}{e}
$$
#### Dark Count Rate:

Count the number of dark pulses in a given time interval to calculate the dark count rate.

#### Signal-to-Noise Ratio (SNR):

Compare the amplitude of the single photo-electron peak to the noise level to determine the SNR.