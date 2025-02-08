import { useState } from "react";
import { Box, Button, Center, Container, HStack, Icon, Input, Stack } from "@chakra-ui/react";
import { FcBusinessman, FcBusinesswoman } from "react-icons/fc";
import { Field } from "./components/ui/field";
import { RadioCardItem, RadioCardRoot } from "./components/ui/radio-card";
import { default as BG } from "./assets/bg.png";

const BMISingle = () => {
  const [view, set_view] = useState<"FORM" | "RESULT">("FORM");
  const [name, set_name] = useState("");
  const [gender, set_gender] = useState("L");
  const [height, set_height] = useState("");
  const [weight, set_weight] = useState("");
  const [age, set_age] = useState("");

  const onSubmit = () => {
    const data = {
      name,
      gender,
      height,
      weight,
      age,
    };

    console.log(data);

    set_view("RESULT");
  };
  return (
    <Container fluid alignSelf={"center"} maxW={"md"} h={"100vh"} py={"2"}>
      {/* form */}
      <Stack
        hidden={view !== "FORM"}
        w={"full"}
        h={"full"}
        justifyContent={"center"}
        alignItems={"center"}
        p={"5"}
        borderWidth={"2px"}
        borderRadius={"md"}
        bgImage={`url(${BG})`}
        bgSize={"cover"}
        bgPos={"left"}
      >
        <Stack
          alignItems={"center"}
          w="full"
          h="95%"
          p="6"
          borderRadius="lg"
          bg="rgba(255, 255, 255, 0.2)"
          boxShadow="0 4px 10px rgba(0, 0, 0, 0.1)"
          backdropFilter="blur(10px)"
          border="1px solid rgba(255, 255, 255, 0.3)"
        >
          <Box px="2em" mb="2em" bg="linear-gradient(135deg, #ff9a3c, #ff6f61)" w="fit-content" shadow={"md"} borderRadius="full">
            <Center color="#3d1a16" fontFamily="Lobster" fontSize="2.5em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
              ScaleUp
            </Center>
          </Box>
          <RadioCardRoot value={gender} onValueChange={(e) => set_gender(e.value)} colorPalette="orange" orientation="vertical" align="center" w="full" defaultValue="L">
            <HStack align={"stretch"} w="full">
              <RadioCardItem
                flex="1"
                label="Laki-laki"
                icon={
                  <Icon fontSize="5xl">
                    <FcBusinessman />
                  </Icon>
                }
                indicator={false}
                key="L"
                value="L"
              />
              <RadioCardItem
                flex="1"
                label="Perempuan"
                icon={
                  <Icon fontSize="5xl">
                    <FcBusinesswoman />
                  </Icon>
                }
                indicator={false}
                key="P"
                value="P"
              />
            </HStack>
          </RadioCardRoot>
          <Field label="Nama" required>
            <Input value={name} onChange={(e) => set_name(e.target.value)} variant="flushed" placeholder="Masukan nama anda" />
          </Field>
          <Field label="Tinggi (cm)" required>
            <Input type="number" value={height} onChange={(e) => set_height(e.target.value)} variant="flushed" placeholder="Masukan tinggi badan anda" />
          </Field>
          <Field label="Berat (kg)" required>
            <Input type="number" value={weight} onChange={(e) => set_weight(e.target.value)} variant="flushed" placeholder="Masukan berat badan anda" />
          </Field>
          <Field label="Usia" required>
            <Input type="number" value={age} onChange={(e) => set_age(e.target.value)} variant="flushed" placeholder="Masukan usia anda" />
          </Field>
          <Button
            onClick={onSubmit}
            w="full"
            bg="linear-gradient(135deg, #ff9a3c, #ff6f61)"
            color="white"
            fontWeight="bold"
            fontSize="lg"
            borderRadius="full"
            shadow="md"
            _hover={{
              transform: "scale(1.05)",
              transition: "all 0.2s ease-in-out",
            }}
            _active={{
              transform: "scale(0.98)",
            }}
            my="5"
          >
            Hitung BMI
          </Button>
        </Stack>
      </Stack>
      {/* result */}
      <Stack
        hidden={view !== "RESULT"}
        w={"full"}
        h={"full"}
        justifyContent={"center"}
        alignItems={"center"}
        p={"5"}
        borderWidth={"2px"}
        borderRadius={"md"}
        bgImage={`url(${BG})`}
        bgSize={"cover"}
        bgPos={"left"}
      >
        <Stack
          alignItems={"center"}
          w="full"
          h="95%"
          p="6"
          borderRadius="lg"
          bg="rgba(255, 255, 255, 0.2)"
          boxShadow="0 4px 10px rgba(0, 0, 0, 0.1)"
          backdropFilter="blur(10px)"
          border="1px solid rgba(255, 255, 255, 0.3)"
        >
          <Box px="2em" mb="2em" bg="linear-gradient(135deg, #ff9a3c, #ff6f61)" w="fit-content" shadow={"md"} borderRadius="full">
            <Center color="#3d1a16" fontFamily="Lobster" fontSize="2.5em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
              ScaleUp
            </Center>
          </Box>
          <Stack spaceY={".5em"} alignItems={"center"} mb="4.35em">
            <Box px="2em" bg="linear-gradient(135deg, #ff9a3c, #ff6f61)" w="fit-content" shadow={"md"} borderRadius="full">
              <Center color="#3d1a16" fontFamily="Lobster" fontSize="1.25em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                Hasil Perhitungan Anda
              </Center>
            </Box>
            <HStack w={"full"} borderRadius={"md"} borderWidth={"2px"}>
              <Stack gap={0} alignItems={"center"} justifyContent={"center"} w={"37.5%"} borderRadius={"md"} borderRightWidth={"2px"}>
                <Icon fontSize="5xl">
                  <FcBusinessman />
                </Icon>
                <Box>Laki-laki</Box>
              </Stack>
              <Stack gap={0} h="full" w={"62%"} p={"1"}>
                <Box lineClamp="2" fontSize="1.1em" fontWeight="700" lineHeight={"1"}>
                  Udin Gamboet
                </Box>
                <Box fontWeight="500" color={"gray"}>
                  25 Tahun
                </Box>
              </Stack>
            </HStack>
            <Box p={"1"} bg="blue.500" w={"fit-content"} shadow={"md"} borderRadius="full">
              <Center mx="1em" color="#fff" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                Tinggi: 165cm | Berat: 60 Kg
              </Center>
            </Box>
            <Box
              _hover={{
                transform: "scale(1.05)",
                transition: "all 0.2s ease-in-out",
              }}
            >
              <Center color="#3d1a16" fontFamily="Lobster" fontSize="2.5em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                21.4
              </Center>
            </Box>
            <Box px="2em" bg="green.400" w="fit-content" shadow={"md"} borderRadius="full">
              <Center color="#fff" fontFamily="Lobster" fontSize="1.5em" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                Berat Badan Ideal
              </Center>
            </Box>
            <Box>
              <Center fontFamily={"heading"} fontWeight="700" textTransform={"uppercase"}>
                Pertahankan pola hidup sehat!
              </Center>
            </Box>
          </Stack>
          <Button
            onClick={() => set_view("FORM")}
            w="full"
            bg="linear-gradient(135deg, #ff9a3c, #ff6f61)"
            color="white"
            fontWeight="bold"
            fontSize="lg"
            borderRadius="full"
            shadow="md"
            _hover={{
              transform: "scale(1.05)",
              transition: "all 0.2s ease-in-out",
            }}
            _active={{
              transform: "scale(0.98)",
            }}
            my="5"
          >
            Hitung Ulang
          </Button>
        </Stack>
      </Stack>
    </Container>
  );
};

export default BMISingle;
