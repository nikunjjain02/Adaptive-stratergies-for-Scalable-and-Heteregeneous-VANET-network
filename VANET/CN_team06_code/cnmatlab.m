T = readtable("trial.csv")
% Assuming the first column is the index and the rest are data columns
indexColumn = T{:, 1};
dataColumns = T{:, 2:end};

% Get the names of the data columns
columnNames = T.Properties.VariableNames(2:end);

% Plot each data column with respect to the index values
figure;
hold on;

for i = 1:size(dataColumns, 2)
    plot(indexColumn, dataColumns(:, i), 'DisplayName', columnNames{i});
end

hold off;

% Add labels and legend
xlabel('Index');
ylabel('Values');
title('Plot of Columns with Respect to Index');
legend('show');