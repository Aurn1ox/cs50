import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases: dict = {}
    previous_cases: dict = {}


    for row in reader:
        state: str = row['state']
        cases: int = int(row['cases'])
        # Add states to dict 
        # initialize list of cases
        if state not in previous_cases:
            previous_cases[state] = [cases]
            new_cases[state] = [cases]

        # If state key exists then update list of cases
        else:
            if len(previous_cases[state]) < 14:
                previous_cases[state].append(cases)

                new_cases[state].append(cases - previous_cases[state][-2])

            else:
                del previous_cases[state][0]
                previous_cases[state].append(cases)

                del new_cases[state][0]
                new_cases[state].append(cases - previous_cases[state][-2])

    return new_cases


def week_avg(cases):
    return round(sum(cases)/7)


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):



    for state in states:
        this_week = new_cases[state][7:]
        last_week = new_cases[state][:7]

        this_week_avg = week_avg(this_week)
        last_week_avg = week_avg(last_week)

        avg_difference = this_week_avg - last_week_avg

        try:
            percentage_difference = ((avg_difference / last_week_avg) * 100)
        except ZeroDivisionError:
            percentage_difference = ((this_week_avg / 1) * 100)

        if percentage_difference > 0:
            print(f"{state} had a 7-day average of {this_week_avg} and an increase of {percentage_difference:.1f}%")
        else:
            print(f"{state} had a 7-day average of {this_week_avg} and a decrease of {percentage_difference:.1f}%")
    




main()
