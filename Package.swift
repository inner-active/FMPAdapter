// swift-tools-version:5.3

// Created by Digital Turbine on 03/12/2025.
// Copyright © 2025 Digital Turbine. All rights reserved.
// License: https://www.digitalturbine.com/sdk-license-fyber

import PackageDescription

let package = Package(
    name: "FMPAdapter",
    platforms: [.iOS(.v13)],
    products: [
        .library(
            name: "FMPAdapter",
            targets: ["FMPAdapterTarget"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/inner-active/DTExchangeSDK-iOS-SPM", .exact("8.4.7"))
    ],
    targets: [
        .target(
            name: "FMPAdapterTarget",
            dependencies: [
                .target(name: "FMPAdapter"),
                .product(name: "DTExchangeSDK", package: "DTExchangeSDK-iOS-SPM")
            ],
            path: "Sources/FMPAdapterTarget"
        ),
        .binaryTarget(
            name: "FMPAdapter",
            url: "https://cdn2.inner-active.mobi/fmp-sdk/files/FMPAdapter-iOS-SPM-8.4.7.zip",
            checksum: "76adc05017945b94f9d2b2f6d9a802998075b003875f6602bbd5341b15539645" 
        ),
    ]
)