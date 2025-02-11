const person = {
    name: "Hyun",
    address: {
        line1: "GangSeo",
        City: "Seoul",
        Country: "Republic of Korea"
    },
    profiles: ['twitter', 'linkedin', 'github'],
    printProfile: () => {
        person.profiles.map(
            (profile) => {
                console.log(profile)
            }
        )
    }
}

export default function LearningJavaScript() {
    return (
        <>
            <div>{person.name}</div>
            <div>{person.address.Country}, {person.address.City}, {person.address.line1}</div>
            <div>{person.profiles[0]}</div>
            <div>{person.profiles[1]}</div>
            <div>{person.profiles[2]}</div>
            <div>{person.printProfile()}</div>
        </>
    )
}