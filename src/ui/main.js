const sensorSections = [
  {
    section: 'Engine & Timing',
    sensors: [
      { id: 'rpm',          label: 'Revolutions Per Minute',    metric: 'rpm'},
      { id: 'cmpPhase',     label: 'Camshaft Phase Offset',     metric: '° crank'},
      { id: 'knockLvl',     label: 'Knock Level',               metric: 'dB'},
      { id: 'sparkAdv',     label: 'Spark Advance',             metric: '° BTDC'}
    ]
  },

  {
    section: 'Air-Flow',
    sensors: [
        { id: 'maf',        label: 'Mass Air Flow',             metric: 'g/s'},
        { id: 'map',        label: 'Manifold Absolute Pressure',metric: 'kPa'},
        { id: 'baro',       label: 'Barometric Pressure',       metric: 'kPa'},
        { id: 'iat',        label: 'Intake Air Temperature',    metric: '°C'},
        { id: 'cat',        label: 'Charge-Air Temperature',    metric: '°C'},
        { id: 'boost',      label: 'Boost Pressure',            metric: 'psi'},
        { id: 'turboSpd',   label: 'Turbocharger Speed',        metric: 'krpm'},
        { id: 'wgPos',      label: 'Waste-Gate Position',       metric: '% open'},
    ]
  },

  {
    section: 'Fuel',
    sensors: [
        { id: 'fuelRail',   label: 'Fuel Rail Pressure',                    metric: 'kPa'},
        { id: 'lpfp',       label: 'Low-Side Fuel Pressure',                metric: 'kPa'},
        { id: 'fuelTemp',   label: 'Fuel Temperature',                      metric: '°C'},
        { id: 'lambda',     label: 'Lambda: Air-Fuel Equivalence Ratio',    metric: ''},
        { id: 'afr',        label: 'Air-Fuel Ratio',                        metric: ''},
        { id: 'ethPct',     label: 'Ethanol Content',                       metric: '%'},
    ]
  },

  {
    section: 'Engine & Exhaust Temperatures',
    sensors: [
        { id: 'ect', label: 'Engine Coolant Temperature',   metric: '°C'},
        { id: 'oilT', label: 'Oil Temperature',             metric: '°C'},
        { id: 'egt', label: 'Exhaust Gas Temperature',      metric: '°C'},
        { id: 'catT', label: 'Catalyst Temperature',        metric: '°C'},
    ]
  },

  {
    section: 'Miscellaneous',
    sensors: [
        {id:'tps', label:'Throttle Position', metric:'%'},
        {id:'oilPress', label:'Oil Pressure', metric:'kPa'},
    ]
  }
];

function buildSensors(sensorSections){

    const frag = document.createDocumentFragment();

    function produceSensor({id, label, metric=''}){
        const row = document.createElement('div');
        row.className = 'sensor-output-row';

        const idElement = document.createElement('span');
        idElement.className = 'sensor-id';
        idElement.textContent = id;

        const labelElement = document.createElement('span');
        labelElement.className = 'sensor-label';
        labelElement.textContent = label;

        const readingElement = document.createElement('span');
        readingElement.className = 'sensor-reading';
        readingElement.id = id;
        readingElement.textContent = '--';

        const metricElement = document.createElement('span');
        metricElement.className = 'sensor-metric';
        metricElement.textContent = metric;

        row.append(idElement, labelElement, readingElement, metricElement);
        frag.appendChild(row);
    }

    function produceTitle({section, sensors = []}){

        const title = document.createElement('h3');
        title.className = 'sensor-title';
        title.textContent = section;

        frag.appendChild(title);

        sensors.forEach(produceSensor);
    }

    sensorSections.forEach(produceTitle);

    return frag;
}

document
    .getElementById('output-sensor-flex-container')
    .appendChild(buildSensors(sensorSections));